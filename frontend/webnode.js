// Basic server template
const app = require("express")();
app.use(require("express").static("."))
const { execFile } = require('child_process');

app.get('/COP3530_Project_2b',(request,response)=>{
    request.query;
   execFile("../sortify.exe", [request.query.category, request.query.algorithm, request.query.direction], { maxBuffer: 50 * 1024 * 1024}, (error, output, stderr) => {
    if (error) {
        console.log(err);
    }
    response.send(output);
    });
});

app.listen(3020,()=>console.log('node.js express server started at port 3020'))