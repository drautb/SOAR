@ECHO off

SET VS_ENV_SCRIPT="C:\Program Files (x86)\Microsoft Visual Studio 11.0\Common7\Tools\VsDevCmd.bat"
SET SLN_FILE="C:\Dev\SOAR\SOAR.sln"

CALL %VS_ENV_SCRIPT%

devenv %SLN_FILE% /Build