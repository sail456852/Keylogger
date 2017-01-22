$MyEmail = "yuzhentech@outlook.com"
$SMTP = "smtp.live.com" 
$To = "wyzsailor@hotmail.com" 
$Subject = "WHAT UP" 
$Body = "What up biatch ! Twice ! This is from Powershell script " 
$Password = ConvertTo-SecureString  "sail456852" -AsPlainText -Force #I reset my password for this account 8:42 PM 1/22/2017
# I tested it on Windows 10 64 bits , it works !  
$Creds = New-Object System.Management.Automation.PSCredential($MyEmail,$Password)

Start-Sleep 2 
Send-MailMessage -To $To -From $MyEmail -Subject $Subject -Body $Body -SmtpServer $SMTP -Credential $Creds -Port 587 -UseSsl -DeliveryNotificationOption OnFailure
