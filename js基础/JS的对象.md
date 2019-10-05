# JS的对象与继承

## JS的模式

JavaScript 的设计是一个简单的基于对象的范式。一个对象就是一系列属性的集合，一个属性包含一个名和一个值。一个属性的值可以是函数，这种情况下属性也被称为方法。

## 对象和属性

### 对象属性的赋值与访问

一个对象的属性是一个被附加在对象的值,可以使用

```js
object.value
```

的方式访问一个对象的属性并使用一下方式赋值

```javascript
object.value = 10
```

当属性不存在的时候,取得的值为`undefine`

### 枚举对象的所有属性

1. for...in...循环 访问一个对象及其原型链中的所有方法
2. Object.keys(o) 方法返回一个对象o(不包含原型)的所有属性的名称的数组
3. Object.getOwnPropertyNames(o) 返回一个对象o的所有属性的**名称**



## 对象的创建

JavaScript 拥有一系列预定义的对象。另外，你可以创建你自己的对象。

### 使用对象的初始化器

每一个 property_i是一个标识符,也可以是一个字面量,并且value_i是一个值将会被赋予property_i的表达式(可以是函数) .方便简洁,但无法重复创建

```javascript
value_1 = 1
value_2 = 2
value_3 = 3
value_4 = 4

var obj = {
	property_1:value_1,//property为一个标识符
    123:value_2,//property为一个Number
    ["property_"+3]:value_3,//property为一个可计算的key名
    "property_4":value_4,//property为一个字符串
    //绑定函数
    property_5:function (event) {
        for(var i = 1;i<event;i++){
            console.log(i)
        }
    }
    function property_6(){
        console.log("hello world")
    }
}

```



### 使用构造函数

- 创建一个构造函数来定义对象的类型(记得首字母大写)
- 通过`new`关键字来创建一个对象实例

```javascript
function Car(make, model, year) {
  this.make = make;
  this.model = model;
  this.year = year;
}
```

现在使用这个函数来创建一个对象

```javascript
var mycar = new Car("Eagle", "Talon TSi", 1993)
```

可是使用这个构造函数创建任意数量的对象

### 使用Object.creat()方法

首相创建一个对象原型,再由这个方法创建自己的对象并重新对其中的属性赋值来使用

```javascript
var Animal = {
  type: "Invertebrates", 
  displayType : function() {  
    console.log(this.type);
  }
}

var dog = Object.create(Animal)

```

### 使用class关键字

```javascript
class Polygon {
    constructor() {
        this.name = "Polygon";
    }
}

```



## JS中的继承

JavaScript 是一种基于原型而不是基于类的面向对象语言。它与传统的基于类的面向对象的语言有本质的区别.可参考[对象模型的细节](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Guide/Details_of_the_Object_Model).js的每一个被继承的对象称为原型(js在ES6中加入的class其实是一个语法糖,本质仍由原型继承来完成).继承的属性可以由构造函数的`prototype`属性直接找到.`prototype`属性可以使得对象具有可以扩展属性的能力

![](/home/qrq/文档/xxbj/js基础/img/继承链图像.jpg)

1. 对于js的继承来说,只有一个结构对象.

2. 每个对象都有一个私有属性`_proto_`指向它的构造函数的原型对象`prototype`,该原型对象也有一`_proto_`对象指向上一个,直到最后的`null`为止.称为原型链

3. 属性的继承,当访问一个对象的属性时候发生的事情

   ```javascript
   function Obj2(value_1,value_2){
       this.property_1 = value_1
       this.property_2 = value_2
       this.e = 10
   }
   
   Obj2.prototype.func_1 = function(){
       console.log("hello world")
       console.log(this.property_1+this.property_2)
   }
   
   //
   // 让我们从一个自身拥有属性a和b的函数里创建一个对象o：
   let f = function () {
       this.a = 1;
       this.b = 2;
    }
    /* 这么写也一样
    function f() {
      this.a = 1;
      this.b = 2;
    }
    */
    let o = new f(); // {a: 1, b: 2}
    
    // 在f函数的原型上定义属性
    f.prototype.b = 3;
    f.prototype.c = 4;
    // 继承Obj2
    f.prototype = Obj2(4,5)
    // 不要在 f 函数的原型上直接定义 f.prototype = {b:3,c:4};这样会直接打破原型链
    // o.[[Prototype]] 有属性 b 和 c
    //  在浏览器中的实现为 o.__proto__ 或者 o.constructor.prototype
    // o.[[Prototype]].[[Prototype]] 是 Obj2.
    // 最后o.[[Prototype]].[[Prototype]].[[Prototype]].[[Prototype]]是null
    // 这就是原型链的末尾，即 null，
    // 根据定义，null 就是没有 [[Prototype]]。
    
    
    console.log(o.a); // 1
    // a是o的自身属性吗？是的，该属性的值为 1
    
    console.log(o.b); // 2
    // b是o的自身属性吗？是的，该属性的值为 2
    // 原型上也有一个'b'属性，但是它不会被访问到。
    // 这种情况被称为"属性遮蔽 (property shadowing)"
    
    console.log(o.c); // 4
    // c是o的自身属性吗？不是，那看看它的原型上有没有
    // c是o.[[Prototype]]的属性吗？是的，该属性的值为 4
    
    console.log(o.d); // undefined
    // d 是 o 的自身属性吗？不是，那看看它的原型上有没有
    // d 是 o.[[Prototype]] 的属性吗？不是，那看看它的原型上有没有
    // o.[[Prototype]].[[Prototype]] 为 Object，
    // o.[[Prototype]].[[Prototype]].[[Prototype]]的property指向null停止搜索
    // 找不到 d 属性，返回 undefined
   ```

4. 方法的继承,在js中,对象的方法是以属性的形式绑定在对象上的.继承模式与属性一致

### 不同的创建对象的方式的继承写法

1. 使用构造函数创建对象时

   ```javascript
   function Graph() {
     this.vertices = [];
     this.edges = [];
   }
   
   Graph.prototype = {
     addVertex: function(v){
       this.vertices.push(v);
     }
   };
   
   var g = new Graph();
   // g 是生成的对象，他的自身属性有 'vertices' 和 'edges'。
   ```

   

2. 使用Object.create()创建时

   ```javascript
   var a = {a: 1}; 
   // a ---> Object.prototype ---> null
   
   var b = Object.create(a);
   // b ---> a ---> Object.prototype ---> null
   console.log(b.a); // 1 (继承而来)
   
   var c = Object.create(b);
   // c ---> b ---> a ---> Object.prototype ---> null
   
   var d = Object.create(null);
   // d ---> null
   console.log(d.hasOwnProperty); // undefined, 因为d没有继承Object.prototype
   ```

   

3. 使用对象的初始化器创建时

   ```javascript
   var o = {a: 1};
   
   // o 这个对象继承了 Object.prototype 上面的所有属性
   // o 自身没有名为 hasOwnProperty 的属性
   // hasOwnProperty 是 Object.prototype 的属性
   // 因此 o 继承了 Object.prototype 的 hasOwnProperty
   // Object.prototype 的原型为 null
   // 原型链如下:
   // o ---> Object.prototype ---> null
   
   var a = ["yo", "whadup", "?"];
   
   // 数组都继承于 Array.prototype 
   // (Array.prototype 中包含 indexOf, forEach 等方法)
   // 原型链如下:
   // a ---> Array.prototype ---> Object.prototype ---> null
   
   function f(){
     return 2;
   }
   
   // 函数都继承于 Function.prototype
   // (Function.prototype 中包含 call, bind等方法)
   // 原型链如下:
   // f ---> Function.prototype ---> Object.prototype ---> null
   ```

   

4. 使用class关键字的时候(许多浏览器还不支持)

   ```javascript
   class Polygon {
     constructor(height, width) {
       this.height = height;
       this.width = width;
     }
   }
   
   class Square extends Polygon {
     constructor(sideLength) {
       super(sideLength, sideLength);
     }
     get area() {
       return this.height * this.width;
     }
     set sideLength(newLength) {
       this.height = newLength;
       this.width = newLength;
     }
   }
   
   var square = new Square(2);
   ```

   

