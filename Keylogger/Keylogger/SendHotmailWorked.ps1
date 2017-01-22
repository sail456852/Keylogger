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


# The following is the modified version : 
$MyEmail = "yuzhentech@outlook.com"
$SMTP = "smtp.live.com" 
$To = "wyzsailor@hotmail.com" 
$Subject = "WHAT UP 1991" 
$Body = "What up biatch ! Twice ! This is from Powershell script " 
$Password = ConvertTo-SecureString  "sail456852" -AsPlainText -Force #I reset my password for this account 8:42 PM 1/22/2017
$File  =  "C:\test\test.png"
# I tested it on Windows 10 64 bits , it works !  
$Creds = New-Object System.Management.Automation.PSCredential($MyEmail,$Password)  #Send Email with pre-defined password .
 
Start-Sleep 2 
Send-MailMessage -To $To -From $MyEmail -Subject $Subject -Body $Body -SmtpServer $SMTP -Credential $Creds -Port 587 -UseSsl -DeliveryNotificationOption OnFailure -Attachments $File


Remove-Variable -Name MyEmail 
Remove-Variable -Name SMTP 
Remove-Variable -Name To
Remove-Variable -Name Subject
Remove-Variable -Name Body 
Remove-Variable -Name Password
Remove-Variable -Name File 
Remove-Variable -Name Creds

exit 1
