# Flask
from flask import Flask,redirect,url_for

app= Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello World'

def about():
    return "This is about page"

@app.route('/blog/<int:postID>')
def show_blog(postID):
    return 'Blog Number %d' %postID

@app.route('/guest/<guest>')
def hello_guest(guest):
    return 'Hello %s as Guest' % guest

@app.route('/rev/<float:revNo>')
def revision(revNo):
    return 'Revision Number %f' % revNo

@app.route('/admin')
def hello_admin():
    return 'Hello admin'

# To bind url to function
app.add_url_rule("/about", "about", about)

@app.route('/user/<name>')
def hello_user(name):
    if name=='admin':
        return redirect(url_for('hello_admin'))
    else:
        return redirect(url_for('hello_guest',guest=name))

if __name__ == '__main__':
    app.run(debug=True)
