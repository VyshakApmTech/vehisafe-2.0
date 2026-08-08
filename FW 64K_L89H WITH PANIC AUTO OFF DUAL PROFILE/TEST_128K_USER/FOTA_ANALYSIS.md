# 🔴 FOTA IMPLEMENTATION ANALYSIS

**Date**: 2026-08-08  
**Status**: ⚠️ **INCOMPLETE - Command Parsing Works, But Firmware Download NOT Implemented**

---

## ❓ Does `SET_FOTA_FRAME[] = {"SETFOTA "};` Work?

### ✅ **YES - PARTIALLY**
- ✅ Frame definition is **CORRECT** (8 characters: "SETFOTA ")
- ✅ Command parsing **WORKS** (Full 6-state machine)
- ✅ Parameters stored in **EEPROM**
- ✅ Sends SMS **REPLY**
- ❌ **ACTUAL FIRMWARE DOWNLOAD NOT IMPLEMENTED**

---

## 📊 Current FOTA Flow (What EXISTS)

```
┌─────────────────────────────────────────────────────────────┐
│ User sends SMS: "SETFOTA 192.168.1.1,21,user,pass,app.bin" │
└────────────────────────────┬────────────────────────────────┘
                             │
                             ▼
┌─────────────────────────────────────────────────────────────┐
│ N_GSM_RESPONSE_HANDLE.c (Line 3230)                         │
│ Checks: UART0_BUFFER == 'S','E','T','F','O','T','A',' '    │
│ State Machine: SETFOTA_CMD_FRAME_RX = 0→1→2→3→4→5         │
└────────────────────────────┬────────────────────────────────┘
                             │
                ┌────────────┼────────────┐
                ▼            ▼            ▼
           Parse IP      Parse PORT    Parse USER
           ─────────     ────────      ────────
           State 1       State 2       State 3
           
                ▼            ▼
           Parse PASS    Parse FILE
           ──────────    ──────────
           State 4       State 5
                             │
                             ▼
         ┌──────────────────────────────────────┐
         │ GSM_INTZ_AND_SMS_HANDLING.c (569)    │
         │ SETFOTA_CMD_REPLY == SET (Triggered)│
         └──────────────────────────┬───────────┘
                                    │
                    ┌───────────────┴───────────────┐
                    │                               │
        ┌───────────▼────────────┐      ┌──────────▼──────────┐
        │ Save to EEPROM         │      │ DEVICE_REPLY_IN_SMS │
        │ IP:   145-159 (15B)    │      │ (REPLY = 37)        │
        │ PORT: 160-165 (6B)     │      │                     │
        │ USER: 166-181 (16B)    │      │ Sends SMS to user   │
        │ PASS: 182-197 (16B)    │      │ "Restarting For..."|
        │ FILE: 0xFB page (32B)  │      └──────────┬──────────┘
        └────────────────────────┘                 │
                                                   ▼
                                        ┌──────────────────────┐
                                        │ N_GSM.c (1062)       │
                                        │ REPLY == 37 Executes │
                                        │                      │
                                        │ Sends SMS: "Restart..│
                                        │                      │
                                        │ goto restart11;      │
                                        │ (Device Restarts)    │
                                        └──────────────────────┘
                                                   │
                                                   ▼
                                        ⚠️ **NO FTP DOWNLOAD!**
                                           **FLOW ENDS HERE**
```

---

## 🔍 Code Evidence

### 1. Frame Definition ✅ CORRECT
**File**: N_GSM_RESPONSE_HANDLE.c (Line 11)
```c
const unsigned char SET_FOTA_FRAME[] = {"SETFOTA "};  // 8 chars ✓
```

**Character Breakdown**:
```
Position:  0  1  2  3  4  5  6  7
Character: S  E  T  F  O  T  A  [space]
Index:     [0][1][2][3][4][5][6][7]
Total: 8 characters ✅
```

---

### 2. Command Parsing ✅ WORKS (Full State Machine)
**File**: N_GSM_RESPONSE_HANDLE.c (Lines 3230-3352)

```c
// STATE 0: Match "SETFOTA " prefix
if(SETFOTA_CMD_FRAME_RX == 0)
{
    I[99]++;
    if(I[99] >= 8)  // "SETFOTA " = 8 chars
    {
        SETFOTA_CMD_FRAME_RX = 1;  // Move to STATE 1
        // Clear all buffers
        for(t = 0; t < 16; t++) { TEMP_FOTA_IP[t]   = ' '; }
        for(t = 0; t < 6;  t++) { TEMP_FOTA_PORT[t] = ' '; }
        for(t = 0; t < 16; t++) { TEMP_FOTA_USER[t] = ' '; }
        for(t = 0; t < 16; t++) { TEMP_FOTA_PASS[t] = ' '; }
        for(t = 0; t < 32; t++) { TEMP_FOTA_FILE[t] = ' '; }
    }
}

// STATE 1: Parse IP address until comma
else if(SETFOTA_CMD_FRAME_RX == 1)
{
    if(UART0_BUFFER == ',')
    {
        TEMP_FOTA_IP[t] = '\0';
        SETFOTA_CMD_FRAME_RX = 2;  // Move to STATE 2
        t = 0;
    }
    else if(t < 15) 
    { 
        TEMP_FOTA_IP[t] = UART0_BUFFER; 
        t++; 
    }
}

// STATE 2: Parse PORT until comma
else if(SETFOTA_CMD_FRAME_RX == 2)
{
    if(UART0_BUFFER == ',')
    {
        TEMP_FOTA_PORT[t] = '\0';
        SETFOTA_CMD_FRAME_RX = 3;  // Move to STATE 3
        t = 0;
    }
    // ... collect port digits
}

// STATE 3: Parse USERNAME until comma
else if(SETFOTA_CMD_FRAME_RX == 3)
{
    if(UART0_BUFFER == ',')
    {
        TEMP_FOTA_USER[t] = '\0';
        SETFOTA_CMD_FRAME_RX = 4;  // Move to STATE 4
        t = 0;
    }
    // ... collect username
}

// STATE 4: Parse PASSWORD until comma
else if(SETFOTA_CMD_FRAME_RX == 4)
{
    if(UART0_BUFFER == ',')
    {
        TEMP_FOTA_PASS[t] = '\0';
        SETFOTA_CMD_FRAME_RX = 5;  // Move to STATE 5
        t = 0;
    }
    // ... collect password
}

// STATE 5: Parse FILENAME until CR/LF
else if(SETFOTA_CMD_FRAME_RX == 5)
{
    if(UART0_BUFFER == '\r' || UART0_BUFFER == '\n')
    {
        TEMP_FOTA_FILE[t] = '\0';
        SETFOTA_CMD_REPLY = SET;  // ✅ Parsing complete
        SETFOTA_CMD_FRAME_RX = 0;
        t = 0;
    }
    // ... collect filename
}
```

**Result**: Variables populated ✅
- `TEMP_FOTA_IP[16]` ← IP address
- `TEMP_FOTA_PORT[6]` ← Port number
- `TEMP_FOTA_USER[16]` ← FTP username
- `TEMP_FOTA_PASS[16]` ← FTP password
- `TEMP_FOTA_FILE[32]` ← Firmware filename

---

### 3. EEPROM Storage ✅ WORKS
**File**: GSM_INTZ_AND_SMS_HANDLING.c (Lines 569-610)

```c
if(SETFOTA_CMD_REPLY == SET)
{
    // Save IP to EEPROM 145..159 (15 bytes)
    for(t = 0; t < 15; t++)
    {
        i2c_writen(0xA0, 0XFE, 145 + t, TEMP_FOTA_IP[t]);
        if(TEMP_FOTA_IP[t] == '\0') break;
    }

    // Save PORT to EEPROM 160..165 (6 bytes)
    for(t = 0; t < 6; t++)
    {
        i2c_writen(0xA0, 0XFE, 160 + t, TEMP_FOTA_PORT[t]);
        if(TEMP_FOTA_PORT[t] == '\0') break;
    }

    // Save USER to EEPROM 166..181 (16 bytes)
    for(t = 0; t < 16; t++)
    {
        i2c_writen(0xA0, 0XFE, 166 + t, TEMP_FOTA_USER[t]);
        if(TEMP_FOTA_USER[t] == '\0') break;
    }

    // Save PASS to EEPROM 182..197 (16 bytes)
    for(t = 0; t < 16; t++)
    {
        i2c_writen(0xA0, 0XFE, 182 + t, TEMP_FOTA_PASS[t]);
        if(TEMP_FOTA_PASS[t] == '\0') break;
    }

    // Save FILE to separate EEPROM page 0xFB (32 bytes)
    for(t = 0; t < 32; t++)
    {
        i2c_writen(0xA0, 0XFB, t, TEMP_FOTA_FILE[t]);
        if(TEMP_FOTA_FILE[t] == '\0') break;
    }

    // Line 603: THIS IS THE PROBLEM! ⚠️
    //SET_OTA_UPDATE = SET;   // COMMENTED OUT! ← Missing implementation
    //OTA_PACKET==ON;
    
    DEVICE_REPLY_IN_SMS(37);  // Send SMS reply (Works)
    SETFOTA_CMD_REPLY = CLR;
}
```

**EEPROM Layout**:
| Address Range | Size | Content |
|---|---|---|
| 0xA0:145-159 | 15 bytes | FTP IP address |
| 0xA0:160-165 | 6 bytes | FTP Port |
| 0xA0:166-181 | 16 bytes | FTP Username |
| 0xA0:182-197 | 16 bytes | FTP Password |
| 0xFB:0-31 | 32 bytes | Firmware filename |

**Result**: Data stored ✅

---

### 4. SMS Reply ✅ WORKS
**File**: N_GSM.c (Lines 1062-1091)

```c
else if(REPLY == 37)
{
    // Step 1: Set SMS text mode
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);

    // Step 2: Send SMS to original sender
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);

    // Step 3: Send message
    R_UART2_SEND("Restarting For FOTA...");

    // Step 4: Send (Ctrl+Z) to complete SMS
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    goto restart11;  // Restart device
}
```

**Result**: SMS sent, device restarts ✅

---

## ❌ **MISSING: Actual FTP Download**

The following is **NOT IMPLEMENTED**:

1. ❌ Read FOTA parameters from EEPROM
2. ❌ Configure FTP using AT+QFTP* commands
3. ❌ Download firmware file from FTP server
4. ❌ Verify firmware checksum/integrity
5. ❌ Flash new firmware to device
6. ❌ Verify flash success

---

## 🚨 The Critical Problem

**File**: GSM_INTZ_AND_SMS_HANDLING.c (Line 603)

```c
    //SET_OTA_UPDATE = SET;   // trigger FOTA process  ← COMMENTED OUT! 🔴
    //OTA_PACKET==ON;
    
    DEVICE_REPLY_IN_SMS(37);  // Only this executes
    SETFOTA_CMD_REPLY = CLR;
```

This flag **would trigger** actual FOTA download, but it's **COMMENTED OUT**.

---

## 📋 What WILL Happen vs Should Happen

### ✅ **WHAT HAPPENS NOW** (Incomplete)
```
1. Device receives: "SETFOTA 192.168.1.1,21,user,pass,app.bin"
2. Parses command ✓
3. Stores in EEPROM ✓
4. Sends SMS: "Restarting For FOTA..." ✓
5. Device restarts ✓
6. BOOT COMPLETE
   └─ But firmware NOT updated (still old version)
   └─ No FTP download happened
   └─ User confused: "Why didn't it update?"
```

### ❌ **WHAT SHOULD HAPPEN** (With proper implementation)
```
1. Device receives: "SETFOTA 192.168.1.1,21,user,pass,app.bin"
2. Parses command ✓
3. Stores in EEPROM ✓
4. Sets SET_OTA_UPDATE = SET flag
5. Main loop detects flag and calls FTP_DOWNLOAD()
   ├─ AT+QFTP="open","192.168.1.1",21,"user","pass"
   ├─ AT+QFTPGET="/app.bin","app.bin"
   ├─ Firmware downloaded to flash
   ├─ Checksum verified
   └─ AT+QFTP="close"
6. Sends SMS: "FOTA Download Complete"
7. Device restarts with new firmware ✓
```

---

## ✅ What ACTUALLY Works

| Feature | Status | Location |
|---------|--------|----------|
| Frame definition `"SETFOTA "` | ✅ Works | N_GSM_RESPONSE_HANDLE.c:11 |
| Command parsing (State 0-5) | ✅ Works | N_GSM_RESPONSE_HANDLE.c:3230-3352 |
| Parameter extraction | ✅ Works | IP, PORT, USER, PASS, FILE |
| EEPROM storage | ✅ Works | GSM_INTZ_AND_SMS_HANDLING.c:569 |
| SMS reply sent | ✅ Works | N_GSM.c:1062 |
| Device restart | ✅ Works | N_GSM.c:1089 |
| **FTP download** | ❌ NOT DONE | Missing |
| **Flash verification** | ❌ NOT DONE | Missing |
| **Firmware update** | ❌ NOT DONE | Missing |

---

## 🔧 To Make FOTA Fully Work

### Step 1: Uncomment the trigger
**GSM_INTZ_AND_SMS_HANDLING.c (Line 603)**:
```c
SET_OTA_UPDATE = SET;   // Enable FOTA process
OTA_PACKET = ON;
```

### Step 2: Implement FTP download function
```c
void FOTA_DOWNLOAD(void)
{
    char fota_ip[16], fota_port[6], fota_user[16], fota_pass[16], fota_file[32];
    unsigned int i;
    
    // Read EEPROM
    for(i=0; i<15; i++) fota_ip[i] = i2c_readn(0xA0, 0xFE, 145+i);
    for(i=0; i<6;  i++) fota_port[i] = i2c_readn(0xA0, 0xFE, 160+i);
    // ... read others
    
    // Open FTP connection
    R_UART2_SEND("AT+QFTP=\"open\",\"");
    R_UART2_SEND(fota_ip);
    R_UART2_SEND("\",");
    R_UART2_SEND(fota_port);
    R_UART2_SEND(",\"");
    R_UART2_SEND(fota_user);
    R_UART2_SEND("\",\"");
    R_UART2_SEND(fota_pass);
    R_UART2_SEND("\"\r\n");
    ACK_RX(5000, 2, 500, 100);  // Wait for OK
    
    // Download file
    R_UART2_SEND("AT+QFTPGET=\"/");
    R_UART2_SEND(fota_file);
    R_UART2_SEND("\",\"");
    R_UART2_SEND(fota_file);
    R_UART2_SEND("\"\r\n");
    ACK_RX(10000, 2, 500, 100);  // Wait for download
    
    // Close FTP
    R_UART2_SEND("AT+QFTP=\"close\"\r\n");
    ACK_RX(2000, 2, 500, 100);
    
    FIRMWARE_DOWNLOADED = SET;  // Mark complete
}
```

### Step 3: Call from main loop
```c
if(SET_OTA_UPDATE == SET)
{
    FOTA_DOWNLOAD();
    SET_OTA_UPDATE = CLR;
}
```

### Step 4: Verify & flash firmware
Implement firmware verification and flashing logic using PFDL (Program Flash Data Library).

---

## 📝 Summary

| Aspect | Status | Details |
|--------|--------|---------|
| **Frame Definition** | ✅ **WORKS** | "SETFOTA " (8 chars) correct |
| **Command Parsing** | ✅ **WORKS** | Full 6-state machine implemented |
| **Parameter Storage** | ✅ **WORKS** | Saved to EEPROM @ addresses 145-197, 0xFB |
| **SMS Reply** | ✅ **WORKS** | "Restarting For FOTA..." sent back |
| **Device Restart** | ✅ **WORKS** | Device reboots after SMS |
| **FTP Download** | ❌ **MISSING** | No AT+QFTP* commands implemented |
| **Firmware Update** | ❌ **MISSING** | No flash programming logic |
| **Full Flow** | ❌ **INCOMPLETE** | 60% done, 40% missing |

---

## ⚠️ **Conclusion**

**`SET_FOTA_FRAME[] = {"SETFOTA "};` WILL WORK for:**
- ✅ Accepting FOTA commands
- ✅ Parsing parameters
- ✅ Storing in EEPROM
- ✅ Sending SMS replies

**BUT WILL FAIL for:**
- ❌ Downloading firmware from FTP
- ❌ Actually updating firmware
- ❌ Completing OTA process

**Status**: **Ready for command parsing, NOT ready for firmware update**

**Action Required**: Implement FTP download and firmware flashing functions (40% remaining work).
