from flask import Flask, render_template, request
import pyotp
import json
import datetime

app = Flask(__name__)


@app.route('/')
def index():
    return render_template('index.html')


@app.route('/gen_secret')
def gen_secret():
    secret_key = pyotp.random_base32()
    return json.dumps({"secret_key": secret_key})


# http://localhost:5000/show_otp?secret_key=secretsecretkey
@app.route('/show_otp')
def show_otp():
    secret_key = request.args.get('secret_key')
    totp = pyotp.TOTP(secret_key)
    time_remaining = totp.interval - datetime.datetime.now().timestamp() % totp.interval
    provisioning_uri = totp.provisioning_uri()
    return json.dumps(
        {
            "otp": totp.now(),
            "time_remaining": time_remaining,
            "provisioning_uri": provisioning_uri,
        }
    )
