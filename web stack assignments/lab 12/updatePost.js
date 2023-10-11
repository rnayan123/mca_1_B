const fs = require('fs')
const path = require('path')


fs.appendFile(
    path.join(__dirname, 'post', 'blogPost.txt'),
    "\nMore data",
    (err) => {
        if(err){
            console.log("Err in data addition");
            return;
        }

        console.log("File contents updated");
    }
)