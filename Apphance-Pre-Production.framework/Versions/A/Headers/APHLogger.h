//
//  Apphance-Pre-Production
//
//  Created by Piotr Wach, Paul Dudek, Pawel Janeczek on 10-01-25.
//  Copyright 2013 uTest. All rights reserved.
//
//	This is the main logger file. Include it in your project
//  along with the Apphance Framework. 

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "APHDefines.h"


/**
* Enum presenting possible logging level
*/
typedef enum {
    APHLogLevelFatal = 16,
    APHLogLevelError = 8,
    APHLogLevelWarning = 4,
    APHLogLevelInfo = 2,
    APHLogLevelVerbose = 0
} APHLogLevel;

/**
* Convinience method to log applications exceptions
*/
APH_EXTERN

void APHUncaughtExceptionHandler(NSException *exception);

/** Logging macros **/

/*
 * Replace all occurences of NSLog with APHLog. 
 * Except for working like normal log it will also send message to Apphance server.
 */
#define APHLog(nsstring_format, ...)    \
    do {                        \
        [APHLogger logWithLevel:APHLogLevelInfo \
        tag:nil \
        line:__LINE__ fileName:[NSString stringWithUTF8String:__FILE__] \
        method:[NSString stringWithUTF8String:__PRETTY_FUNCTION__] \
        stacktrace:[NSThread callStackReturnAddresses]\
        format:nsstring_format, \
        ##__VA_ARGS__];\
} while(0)

/*
 * Works as the one above, except it provides additional configuration options
 */
#define APHExtendedLog(APHLogLevel, nsstring_tag, nsstring_format, ...)    \
    do {                        \
        [APHLogger logWithLevel:(APHLogLevel) \
        tag:(nsstring_tag) \
        line:__LINE__ fileName:[NSString stringWithUTF8String:__FILE__] \
        method:[NSString stringWithUTF8String:__PRETTY_FUNCTION__] \
        stacktrace:[NSThread callStackReturnAddresses] \
        format:nsstring_format, \
        ##__VA_ARGS__];\
} while(0)


//! Main apphance API class
/**
* Main apphance API class
* @see https://help.apphance.com/library-installation/ios/tutorial
 */
@interface APHLogger : NSObject {

}

/** General setup methods **/

/**
* This will enable/disable shake gesture to report a problem.
* Default it YES.
* Be sure to call this before starting Apphance session otherwise it will have no effect.
* @param shakeEnabled
 */
+ (void)setReportOnShakeEnabled:(BOOL)shakeEnabled;

/**
* This will enable/disable double slide gesture to report a problem.
* Default it NO.
* Be sure to call this before starting Apphance session otherwise it will have no effect.
* @param doubleSlideEnabled
 */
+ (void)setReportOnDoubleSlideEnabled:(BOOL)doubleSlideEnabled;

/**
* This will override current application version name.
* Default one is obtained by CFBundleShortVersionString.
* Be sure to call this before starting Apphance session otherwise it will have no effect.
* @param versionName Application version name
 */
+ (void)setVersionName:(NSString *)versionName;

/**
* This will override current application version code.
* Default one is obtained by CFBundleVersion.
* Be sure to call this before starting Apphance session otherwise it will have no effect.
* @param versionNumber Application version number
 */
+ (void)setVersionNumber:(NSString *)versionNumber;

/**
* Logs exception. Screenshot will be included in the data sent to the server.
* You can use APHUncaughtExceptionHandler as a convenience accessor to this method.
* @param error Exception that will be passed to Apphance
 */
+ (void)logApplicationException:(NSException *)error;

/**
* This method will register object for logging, meaning each and every method sent to it will be logged, including timestamp.
* See documentation for more information.
* @param object Object that will be registered for logging
 */
+ (id)registerObjectForLogging:(id)object;

/**
* Forces the contents of the session log buffer to be send.
 */
+ (void)flush;

/** Starting new session **/

/**
* Starting APH session. Should be called once per application run - doing otherwise will result in an undefined behavior.
* @param applicationID Application ID that you can get from Apphance
* @param apphanceMode Apphance mode:kAPHApphanceModeQA, kAPHApphanceModeSilent
* @param withUtest uTest enabled
 */
+ (void)startNewSessionWithApplicationKey:(NSString *)applicationID apphanceMode:(NSString *)apphanceMode withUtest:(BOOL)withUtest;

/**
* uTest is disabled by default.
* @see APHLogger#startNewSessionWithApplicationKey:apphanceMode:withUtest:
 */
+ (void)startNewSessionWithApplicationKey:(NSString *)applicationID apphanceMode:(NSString *)apphanceMode;

/**
* Default mode kAPHApphanceModeQA.
* uTest is disabled by default.
* @see APHLogger#startNewSessionWithApplicationKey:apphanceMode:withUtest:
 */
+ (void)startNewSessionWithApplicationKey:(NSString *)applicationID;

/**
* Only available on Production library.
* @see https://help.apphance.com/library-installation/ios/tutorial
*/
+ (void)feedback:(NSString *)title placeholder:(NSString *)placeholder;

/**
* Only available on Production library.
* @see https://help.apphance.com/library-installation/ios/tutorial
*/
+ (void)feedback:(NSString *)title;

/**
* Only available on Production library.
* @see https://help.apphance.com/library-installation/ios/tutorial
*/
+ (void)feedback;

/**
* Only available on Production library.
* @see https://help.apphance.com/library-installation/ios/tutorial
*/
+ (void)sendFeedback:(NSString *)feedback;

@end


/**
* Despite being called private, you can generally call these method, if you wish.
* However, this is strongly discouraged, since given macros and functions are more convenient way of using APH.
 */
@interface APHLogger (PrivateAccessors)

+ (void)logWithLevel:(APHLogLevel)level tag:(NSString *)tag line:(NSInteger)line fileName:(NSString *)fileName method:(NSString *)method stacktrace:(NSArray *)stacktrace format:(NSString *)format, ...;

@end
