//
//  utestAppDelegate.m
//  helloWorldApphanceIntegration
//
//  Created by Wojciech Kedzierski on 31.08.2012.
//  Copyright (c) 2012 Wojciech Kedzierski. All rights reserved.
//

#import "utestAppDelegate.h"

@implementation utestAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad) {
        UISplitViewController *splitViewController = (UISplitViewController *)self.window.rootViewController;
        UINavigationController *navigationController = [splitViewController.viewControllers lastObject];
        splitViewController.delegate = (id)navigationController.topViewController;
    }
   
    /*********************************************/
    /* Very Important Details for Apphance Users */
    /*********************************************/
    // You must insert your Apphnace application key in the next line of code:
    
    [APHLogger startNewSessionWithApplicationKey:@"Your-Apphance-Application-Key-Goes-Here" apphanceMode:kAPHApphanceModeQA];
    
    // If you do not have an Apphance application key, you must first create a free account.
    // Visit http://www.apphance.com for more information about how to create your account.
    //
    // If you already have an Apphance account, login to the Apphance control panel at: https://panel.apphance.com
    // Create a new application (if you have not done so already).
    // Your application key can be retrieved at any time from the "Settings" tab on the left menu.
    
    // The following line handles all uncaught exceptions and will send them to Apphance the next
    // time the application starts. Add this line to enable crash reporting.
    
    NSSetUncaughtExceptionHandler(&APHUncaughtExceptionHandler);
    
    // For more Apphance help, visit http://help.apphance.com
    
    /***********************/
    /* End Apphance Config */
    /***********************/
    
    return YES;
}
							
- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
