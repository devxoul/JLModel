# JLModel

JLModel allows you to manage models in very simple way.


## Installation

### Using git submodule

```
$ git submodule add https://github.com/Joyfl/JLModel.git myproject/libs/JLModel
$ git submodule update
```

Then add folder to your Xcode project.


### or just download it.


## Defining Model Classes

### Basic Types

Model classes are subclass of JLModel. Don't forget to write a `Model()` in `.h` files. `Model()` makes it available to use short type definition and relationship definition.

###### Sample model class definition:


```
#import "JLModel.h"

Model(User) // DON'T forget this.

@interface User : JLModel

Integer id;
String name;
Date created_time;

@end
```

### Relationship

You can define relationship between models with `ToOne()` and `ToMany()`. These need first argument as target model class.

###### One-to-one relationship example:
```
#import "Address.h" // Another model class
...
Integer id;
String name;
ToOne(Address) address;
```

###### One-to-many relationship example:
```
#import "Post.h" // Another model class
...
Integer id;
String name;
ToMany(Post) posts;
```

### Non-model Array
If there's an array of primitive type or non-model type, you can use `Array` to describe it. `Array` object can contain any type of data such as `NSInteger`, `NSDictionary`.
```
Array myArray;
```

### All types

| Type | Converted to |
|---|---|
| Integer | NSNumber * |
| Float | NSNumber * |
| Boolean | NSNumber * |
| String | NSString * |
| Date | NSDate * |
| Array | NSArray * |
| ToMany | NSArray\<Class> * |
| ToOne | Class * |

## Creating Model Instance

### Empty Model Instance

You can create model instance with objective-c grammar.

```
user = [[User alloc] init];
```

### Model with Dictionary

JLModel supports initializing from an `NSDictionary` object. Name of model class properties and its of `NSDictionary` keys need to be same.

For example, you retrieved a JSON data like below:

```
{
	"id": 3,
	"name": "devxoul",
	"posts": [
		{
		    "id": 120,
		    "title": "Awesome Framework: JLModel",
		    "content": "It is awesome!"
	    },
	    {
	    	"id": 142,
	    	"title": "Hello, World!",
	    	"content": "Good morning guys."
	    }
	]
}
```

and defined model class like below:
```
#import "JLModel.h"
#import "Post.h"

Model(User)

@interface User : JLModel

Integer id;
String name;
ToMany(Post) posts;

@end
```

Then you can create model class instance with `- [JLModel initWithDictionary:]` method.

```
NSDictionary *userDict = // NSDictionary from retrieved JSON.
User *user = [[User alloc] initWithDictionary:userDict];

// User: id=3, name=devxoul
NSLog(@"User: id=%@, name=%@", user.id, user.name);

// Posts: 2
NSLog(@"Posts: %d", user.posts.count);
```

## Warning

This is on development. Please care of using.