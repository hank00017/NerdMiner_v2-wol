#ifndef WOL_SETUP_HTML_H
#define WOL_SETUP_HTML_H

const char* WOL_SETUP_PAGE = R"(
<!DOCTYPE html>
<html>
<head>
    <title>Wake-on-LAN Controller</title>
    <meta charset='UTF-8'>
    <meta name='viewport' content='width=device-width,initial-scale=1.0'>
    <style>
        
    </style>
</head>
<body>
    <div class="card">
        <h1>Wake-on-LAN Controller</h1>
        <h3 style="margin-top:-8px">Please add device to use</h3>
        <form method="POST" action="/addDevice">
            <label>Device Name
                <input name="name" placeholder="My PC" required>
                <div class="tip">e.g. My PC</div>
            </label>
            <label>MAC Address
                <input name="mac" placeholder="AA:BB:CC:DD:EE:FF" pattern="^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$" required>
                <div class="tip">Format: AA:BB:CC:DD:EE:FF</div>
            </label>
            <label>Broadcast IP
                <input name="ip" value="192.168.1.255" required>
                <div class="tip">Usually network broadcast (e.g. 192.168.1.255)</div>
            </label>
            <button style="margin-top: 35px;" type="submit">Add Device</button>
        </form>
    </div>
</body>
</html>
)";

#endif