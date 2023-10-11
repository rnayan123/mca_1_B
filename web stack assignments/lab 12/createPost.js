const fs=require('fs');
const path=require('path');
fs.writeFile(path.join(__dirname,'post','blogpost.txt'),'hello',(err)=>{
    if(err){
        throw err;
    }
    console.log('file created');
});