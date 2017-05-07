//
//  TapResearch.h // AppDelegate.h
#import <TapResearchSDK/TapResearchSDK.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate, TapResearchDelegate>

//  TapResearchSDK
//
//  Copyright (c) 2015 TapResearch. All rights reserved.
//

#import <Foundation/Foundation.h>// AppDelegate.m

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions 
{
  // Your code logic

  [TapResearch initWithApiToken:c769c374c76f9813f5bed079575fe36e
   delegate:self];
}

@protocol TapResearchDelegate;// AppDelegate.m

- (void)tapResearchDidReceiveRewardWithQuantity:(NSInteger)quantity transactionIdentifier:(NSString *)transactionIdentifier
{

  // Your virtual currency management logic goes here
  NSLog(@"Player has earned %u gold coins!", (unsigned)quantity);

}
@protocol TapResearchSurveyDelegate;#import <TapResearchSDK/TapResearchSDK.h>

- (IBAction)surveyButtonTouched:(id)sender
{
  [TapResearch showSurvey]

/**
 Main interface for you to communicate with the TapResearch service.
 */
@interface TapResearch : NSObject

/**
 @method: initWithApiToken:delegate:
 @abstract: Initialize TapResearch with your apiToken and callback handler.
 
 @param: apiToken Your app's unique identifier.
 @param: delegate: The class that will implement the TapResearchDelegate protocol.
 */
+ (void)initWithApiToken:(NSString *)apiToken delegate:(id<TapResearchDelegate>)delegate;

/**
 @method: isSurveyAvailable
 @abstract: Check if there is a survey available for the user.
 */
+ (BOOL)isSurveyAvailable;

/**
 @method: showSurvey
 @abstract: Takes the user into a survey. Shows an alert modal asking if the user would like to "cancel" or "continue".
 */
+ (void)showSurvey;

/**
 @method: showSurveyWithDelegate:
 @abstract: Takes the user into a survey. Shows an alert modal asking if the user would like to "cancel" or "continue".
 @param: delegate: notifies your app which button was selected in the alert modal.
 */
+ (void)showSurveyWithDelegate:(id<TapResearchSurveyDelegate>)delegate;

/**
 @method: setUniqueUserIdentifier
 @abstract: Store unique user identifier for re-identification purposes
 
 @param: userIdentifier: Unique user identifier. Required if you have opted for server to server postback.
 */

+ (void)setUniqueUserIdentifier:(NSString *)userIdentifier;

@end

@protocol TapResearchDelegate <NSObject>

/**
 @method: tapResearchDidReceiveRewardWithQuantity:transactionIdentifier:
 @abstract: Notifies the delegate that a user has earned an in-app reward.
 */
- (void)tapResearchDidReceiveRewardWithQuantity:(NSInteger)quantity transactionIdentifier:(NSString *)transactionIdentifier;

@optional

/**
 method: tapResearchSurveyAvailable
 abstract: Notifies the delegate when a survey is available.
 */
- (void)tapResearchOnSurveyAvailable;

/**
 method: tapResearchSurveyNotAvailable
 abstract: Notifies the delegate when a survey is not available.
 */
- (void)tapResearchOnSurveyNotAvailable;// InGameShopController.m
#import <TapResearchSDK/TapResearchSDK.h>

@implementation InGameShopController

- (void)viewDidLoad
{
  [super viewDidLoad];

  // Only add button if isSurveyAvailable returns true.
  if ([TapResearch isSurveyAvailable]) {
    // Add button
  }
}

...


@end

@protocol TapResearchSurveyDelegate <NSObject>

@optional
/**
 method: tapResearchSurveyModalOpened
 abstract: Notifies the delegate when a user opens the survey modal.
 */
- (void)tapResearchSurveyModalOpened;

/**
 @method: tapResearchSurveyModalDismissed
 @abstract: Notifies the delegate when a user dismisses the survey modal.
 */
- (void)tapResearchSurveyModalDismissed;

@end

