Promise.reject("Testing static reject").then(function (reason) {
    // 未被调用
    console.log("未被调用的")
}, function (reason) {
    console.log(reason); // "Testing static reject"
});

Promise.reject(new Error("fail")).then(function (result) {
    // 未被调用
    console.log("未被调用的")
}, function (error) {
    console.log(error); // stacktrace
});