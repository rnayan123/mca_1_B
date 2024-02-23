    # flask application
from flask import Flask,render_template,redirect,url_for,request

app = Flask(__name__)


@app.route('/')
def index():
    return render_template('salary.html')

@app.route('/success/<int:score>')
def success(score):
    res=''
    if score < 50000:
        res = 'B grade'
    else:
        res = 'A grade'
    return render_template('salary_result.html',result=res)

@app.route('/fail/<int:score>')
def fail(score):
    return 'The person has failed and the marks is %d' % score


@app.route('/submit',methods=['POST','GET'])
def submit():
    total_score = 0
    if request.method == 'POST':
        da = float(request.form['da'])
        basic = float(request.form['basic'])
        hra= float(request.form['hra'])

        total_score = (da+basic+hra)
        return redirect(url_for('success',score=total_score))
    else:
        return render_template('form.html')






# @app.route('/admin')
# def admin():
#     return render_template('app.html')

# @app.route('/user/<username>')
# def show_user_profile(username):
#     if username == 'admin':
#         return redirect(url_for('admin'))
#     else:
#         return redirect(url_for('guest',guest=username))


# @app.route('/blog/<int:postID>')
# def show_blog(postID):
#     return 'Blog Number %d' % postID

# def about():
#     return 'About Page'
# app.add_url_rule('/about','about',about) 

# @app.route('/guest/<guest>')
# def guest(guest):
#     return 'Hello %s as Guest' % guest

# @app.route('/rev/<float:revNo>')
# def revision(revNo):
#     return 'Revision Number %f' % revNo





if __name__ == '__main__':
    app.run(debug=True)
