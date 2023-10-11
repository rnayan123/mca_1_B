const fs = require('fs')
const path = require('path')


fs.unlink(
    path.join(__dirname, 'post', 'blogPost.txt'),
    (err) => {
        if(err){
            console.log("No such file exsists");
            return;
        }

        console.log("file Deleted");
    }
);