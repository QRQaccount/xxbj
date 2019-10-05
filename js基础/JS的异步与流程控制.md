# JS的异步机制

## 同步与异步

![](https://github.com/QRQaccount/xxbj/blob/master/js%E5%9F%BA%E7%A1%80/img/%E5%90%8C%E6%AD%A5%E4%B8%8E%E5%BC%82%E6%AD%A5.png)

- 同步:在执行时如果执行函数需要等待,则会一直等待到函数处理完再继续执行后面的程序
- 异步:执行完函数或方法后，不必阻塞性地等待返回值或消息，只需要向系统委托一个异步过程，那么当系统接收到返回值或消息时，系统会自动触发委托的异步过程，从而完成一个完整的流程。 

## JS的单线程

js是单线程的,因为浏览器在运行时只开启了一个JS引擎线程来解析和执行JS.异步执行过程中的耗时的部分全部由JS引擎完成.即JS是单线程的但是JS引擎是多线程的.对于JS的常用运行环境--浏览器,一般有几个常驻线程

- 渲染引擎线程：顾名思义，该线程负责页面的渲染
- JS引擎线程：负责JS的解析和执行
- 定时触发器线程：处理定时事件，比如`setTimeout`,` setInterval`
- 事件触发线程：处理DOM事件
- 异步http请求线程：处理http请求

## 消息队列与事件循环

![](https://github.com/QRQaccount/xxbj/blob/master/js%E5%9F%BA%E7%A1%80/img/%E6%B6%88%E6%81%AF%E9%98%9F%E5%88%97%E4%B8%8E%E4%BA%8B%E4%BB%B6%E5%BE%AA%E7%8E%AF.png)

主线程运行的时候，产生堆（heap）和栈（stack），栈中的代码调用各种外部API，它们在"任务队列"中加入各种事件（click，load，done）。当栈中的代码优先执行完，主线程就会去读取"任务队列"，依次执行那些事件所对应的回调函数。执行栈中的代码（同步任务），总是在读取"任务队列"（异步任务）之前执行。JS引擎线程从消息队列中读取任务是不断循环的，每次栈被清空后，都会在消息队列中读取新的任务，如果没有新的任务，就会等待，直到有新的任务，这就叫事件循环。![](https://github.com/QRQaccount/xxbj/blob/master/js%E5%9F%BA%E7%A1%80/img/nodejs%E4%BA%8B%E4%BB%B6%E5%BE%AA%E7%8E%AF.png)

1. V8引擎解析JavaScript脚本。
2. 解析后的代码，调用Node API
3. [`libuv库`](https://github.com/libuv/libuv)负责Node API的执行。它将不同的任务分配给不同的线程，形成一个Event Loop（事件循环），以异步的方式将任务的执行结果返回给V8引擎。
4. V8引擎再将结果返回给用户

## Promise对象的使用

`Promise` 是一个对象，它代表了一个异步操作的最终完成或者失败.`Promise` 是异步编程的一种解决方案，比传统的解决方案——回调函数和事件——更合理和更强大.当使用回调函数过多的时候过多的回调函数会导致代码结构变差,维护性下降,可读性下降.有了`Promise`对象，就可以将异步操作以同步操作的流程表达出来，避免了层层嵌套的回调函数。此外，`Promise`对象提供统一的接口，使得控制异步操作更加容易.

### Promise的状态

- pending初始状态
- fulfilled: 意味着操作成功完成
- rejected: 意味着操作失败

pending 状态的 Promise 对象可能会变为fulfilled 状态并传递一个值给相应的状态处理方法，也可能变为失败状态（rejected）并传递失败信息。当其中任一种情况出现时，Promise 对象的 `then` 方法绑定的处理方法（handlers ）就会被调用（then方法包含两个参数：onfulfilled 和 onrejected，它们都是 Function 类型。当Promise状态为*fulfilled*时，调用 then 的 onfulfilled 方法，当Promise状态为*rejected*时，调用 then 的 onrejected 方法， 所以在异步操作的完成和绑定处理方法之间不存在竞争）。<br/>因为 `Promise.prototype.then` 和  `Promise.prototype.catch` 方法返回promise 对象， 所以它们可以被链式调用。![](https://github.com/QRQaccount/xxbj/blob/master/js%E5%9F%BA%E7%A1%80/img/promises_then_catch.png)

### Promise的方法

1. Promise.all(iterable)<br>这个方法返回一个新的promise对象，该promise对象在iterable参数对象里所有的promise对象都成功的时候才会触发成功，一旦有任何一个iterable里面的promise对象失败则立即触发该promise对象的失败。这个新的promise对象在触发成功状态以后，会把一个包含iterable里所有promise返回值的数组作为成功回调的返回值，顺序跟iterable的顺序保持一致；如果这个新的promise对象触发了失败状态，它会把iterable里第一个触发失败的promise对象的错误信息作为它的失败错误信息。Promise.all方法常被用于处理多个promise对象的状态集合。参考JQuert.when方法
2. Promise.race(iterable)<br>当iterable参数里的任意一个子promise被成功或失败后，父promise马上也会用子promise的成功返回值或失败详情作为参数调用父promise绑定的相应句柄，并返回该promise对象。
3. Promise.reject(reason)<br>返回一个状态为失败的Promise对象，并将给定的失败信息传递给对应的处理方法
4. Promise.resolve(value)<br>返回一个状态由给定value决定的Promise对象。如果该值是thenable(即，带有then方法的对象)，返回的Promise对象的最终状态由then方法执行决定；否则的话(该value为空，基本类型或者不带then方法的对象),返回的Promise对象状态为fulfilled，并且将该value传递给对应的then方法。

### Promise的原型

1. Promise.prototype.catch(onRejected)<br>添加一个拒绝(rejection) 回调到当前 promise, 返回一个新的promise。当这个回调函数被调用，新 promise 将以它的返回值来resolve，否则如果当前promise 进入fulfilled状态，则以当前promise的完成结果作为新promise的完成结果.
2. Promise.prototype.then(onFulfilled, onRejected)<br>添加解决(fulfillment)和拒绝(rejection)回调到当前 promise, 返回一个新的 promise, 将以回调的返回值来resolve.
3. Promise.prototype.finally(onFinally)<br>添加一个事件处理回调于当前promise对象，并且在原promise对象解析完毕后，返回一个新的promise对象。回调会在当前promise运行完毕后被调用，无论当前promise的状态是完成(fulfilled)还是失败(rejected)



### Promise的创建

`Promise` 对象是由关键字 `new` 及其构造函数来创建的。该构造函数会把一个叫做“处理器函数”（executor function）的函数作为它的参数。这个“处理器函数”接受两个函数——`resolve` 和 `reject` ——作为其参数。当异步任务顺利完成且返回结果值时，会调用 `resolve` 函数；而当异步任务失败且返回失败原因（通常是一个错误对象）时，会调用`reject` 函数。
