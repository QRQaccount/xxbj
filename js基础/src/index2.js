/**
 * 
 * 观察程序的执行顺序
 */


var myPromise = new Promise(function (resolve, reject) {
    let a = 0;
    console.log("立即执行")
    setTimeout(() => {
        console.log("lalala")
        resolve("成功的消息") //调用resolve传入值
    }, 300);
})

myPromise.then(function (onfulfilled) {
    console.log(onfulfilled + "--来自回调")
    console.log("成功执行--then")
}, function (onrejected) {
    console.log(onrejected + "--来自回调")
    console.log("错误执行--then")
}).catch(function () {
    console.log("错误执行--catch")
}).finally(function () {
    console.log("最终执行")
})

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