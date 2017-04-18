'''
Flask app that handle with the requests.
The actual problem is that the transformer function is called once per server reload.
'''

from flask import Flask, render_template, request

from trace import transformer

app = Flask(__name__)

@app.route('/')
def index():
    return 'My apps!'

@app.route('/prolog', methods=['GET', 'POST'])
def prolog():
    if request.method == 'POST':
        title = "Not easy"
        trace = request.form['trace']
        tree = transformer(trace)
        return render_template('prolog.html', title=title, tree=tree)
    else:
        title = "Welcome, paste your trace log to gerate a tree."

        return render_template('prolog.html', title=title, tree='')
