/**
 * This Header just contains helpful macros to use in various projects
 */

#define SAFE_DELETE(o)              if (o != nullptr) { delete o; o = nullptr; }
