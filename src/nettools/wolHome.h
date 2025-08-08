#ifndef WOL_HOME_H
#define WOL_HOME_H


const char* WOL_HOME_PAGE = R"(
<!DOCTYPE html>
<html>
<head>
    <title>Wake-on-LAN Controller</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <div class="container">
        <h1>Wake-on-LAN Controller</h1>
        <div class="device-list">
            {{DEVICE_BUTTONS}} 
            <!-- This will be replaced with device buttons -->
        </div>
      
    </div>
</body>
</html>
)";

#endif