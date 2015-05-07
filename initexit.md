## init and exit ##

**Example 1**

init - kernel takes this keyword as hint and is used only during the initialization phase and frees up used memory resources

You should add init immediately before the function name, like:
static void init initme(int x, int y)
{
> extern int z; z = x **y;
}**


**Example 2**

If the function has a prototype somewhere, you can also add init between closing brace of the prototype and semicolon:

extern int initialize\_foobar\_device(int, int, int) init;


**Example 3**

For initialized data:
You should insert initdata between the variable name and equal sign followed by value, e.g.:
This variable should be initialized not at file scope(global variable), rather should be within a function
Also data cannot be "const"

static int init\_variable initdata = 0;

static char linux\_logo[.md](.md) initdata = { 0x32, 0x36, ... };


**Example 4**

devexit -

Functions marked as devexit may be discarded at kernel link time, depending on config options.
Pointers to devexit functions must use devexit\_p(function\_name), the wrapper will
insert either the function\_name or NULL, depending on the config options.

If config option is module or hotplug, devexit can be called
If config option is driver, devexit is NULL, so there is no meaning calling here

#if defined(MODULE) || defined(CONFIG\_HOTPLUG)

#define devexit\_p(x) x

#else

#define devexit\_p(x) NULL

#endif

#endif /_**LINUX\_INIT\_H**/_


## IMP NOTE: .init and .exit are the init section of the driver ##


Mark functions and data as being only used at initialization
or exit time.

#define init		attribute ((section (".text.init")))

#define exit		attribute ((unused,
section(".text.exit")))

#define initdata	attribute ((section (".data.init")))

#define exitdata	attribute ((unused, section
(".data.exit")))

#define initsetup	attribute ((unused,section (".setup.init")))

#define init\_call	attribute ((unused,section (".initcall.init")))

#define exit\_call	attribute ((unused,section (".exitcall.exit")))