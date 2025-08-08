#ifndef WOL_HTML_H
#define WOL_HTML_H


const char* WOL_HTML_PAGE = R"(
<!DOCTYPE html>
<html>
<head>
    <title>Wake-on-LAN Controller</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
                body {
            font-family: Arial, sans-serif;
            max-width: 600px;
            margin: 50px auto;
            padding: 20px;
            background-color: #f5f5f5;
        }
        .container {
            background-color: white;
            padding-bottom: 10px;
            padding-top: 30px;
            padding-right: 30px;
            padding-left: 30px;
            
            border-radius: 32px;
            box-shadow: 0 13px 10px rgba(0, 0, 0, 0.51);
        }
        h1 {
            color: #1e84a4;
            text-align: center;
        }
        h3 {
            color: #000000;
            text-align: center;
            margin-top: 40px;
        }
        button {
            font-size: 37px;
            width: 100%; 
            height: 75px;
            background-color: #1aa420;
            color: white;
            padding: 10px 20px;
            border: none;
            border-radius: 74px;
            cursor: pointer;
            margin-bottom: 24px;            
        }
        button:hover {
            background-color: #45a049;
        }
    </style>
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