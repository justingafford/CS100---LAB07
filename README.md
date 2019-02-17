# Abstract Factory Pattern

> Author: Brian Crites ([@brrcrites](https://github.com/brrcrites))

**You *must* work in a group of two for this lab**

In the composite pattern lab you created two leaf type nodes `Op` and `Rand` which had `evalute()` and `stringify()` functions which returned the value of the object. In this lab you will create categories of subclasses for each of these original leaf classes and then create an abstract factory to ensure that each expression tree only has objects from a single category. First, create the following subclasses for `Op` and `Rand`

* `PrecisionOp` and `PrecisionRand` (which are subclasses of `Op` and `Rand` respectively) will override `stringify()` to convert the internal value with a specific number of values after the decimal. You will need to utilize the [setprecision](http://www.cplusplus.com/reference/iomanip/setprecision/) stream modifier and stringstreams for this.
* `SciOp` and `SciRand` (which are subclasses of `Op` and `Rand` respectively) will override `stringify()` to convert the internal value in scientific notation. You will need to utilize the [scientific](http://www.cplusplus.com/reference/ios/scientific/) stream modifier and stringstream for this.

You might find [this link on stringstreams](https://thispointer.com/c-convert-double-to-string-and-manage-precision-scientific-notation/) useful in addition to the official documentation. You should create unit tests for the above classes and commit the changes to your code before moving on to the next portion of the lab. Once that is complete, use the following class declaration as the interface for your abstract factory pattern classes.

```c++
class BaseFactory {
    public:
        /* Constructor */
        BaseFactory();

        /* Pure Virtual Production Function */
        virtual Op* createOp(double value) = 0;
        virtual Rand* createRand() = 0;
};
```

Once you have created the base class for the abstract factory you will need to create three concrete subclass factories capable of producing the proper object from each category of products (standard double, scientific, and precision).

## Submission

To receive credit for this lab you must show an example program to your TA that demonstrates the full functionality of this pattern along with the composite and strategy patterns, and must explain to your TA the structure of both your classes and how they interact. You must also show your TA the tests that you have created for validating your decorator class and its interactions with the other classes.
