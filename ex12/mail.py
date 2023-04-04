import smtplib
from email import encoders
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart

server = smtplib.SMTP('smtp.gmail.com', 587)

server.starttls()

server.ehlo()

server.login('karimchaouki50@gmail.com', 'fjjumazwerabdtvq')


msg = MIMEMultipart()
msg['From'] = 'karimchaouki50@gmail.com'
msg['To'] = 'votepa4633@djpich.com'
msg['Subject'] = 'Testing'

message = 'hello world'

msg.attach(MIMEText(message, 'plain'))

filename = 'tt.png'

attachment = open(filename, 'rb')

p = MIMEBase('application', 'octet-stream')
p.set_payload(attachment.read())

encoders.encode_base64(p)
p.add_header('Content-Disposition', f'attachment; filename={filename}')
msg.attach(p)

server.sendmail('karimchaouki50@gmail.com', 'falim78923@duiter.com', msg.as_string())