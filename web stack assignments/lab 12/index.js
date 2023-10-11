const fs = require('fs')
const path = require('path')


fs.mkdir(
    path.join(__dirname, '/posts'),
    (err) => {
        if(err){
            console.log(err);
            console.log("Folder with that name already exsits");
            return;
        }

        console.log("posts folder created");
    }
);