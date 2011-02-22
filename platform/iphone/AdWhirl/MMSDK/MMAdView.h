//
//  MMAdView.h
//
//  Copyright 2010 Millennial Media Inc. All rights reserved.
//


#import <UIKit/UIKit.h>

@protocol MMAdDelegate;

typedef enum AdType {
	MMBannerAdTop = 1,  //320x53
	MMBannerAdBottom = 2,
	MMBannerAdRectangle = 3,
	MMFullScreenAdLaunch = 4,
	MMFullScreenAdTransition = 5 //interstitial
} MMAdType;




@interface MMAdView : UIView {

	id<MMAdDelegate> delegate;
}

@property(nonatomic,assign) id<MMAdDelegate> delegate;
	



+ (MMAdView *) adWithFrame:(CGRect)frame type:(MMAdType) type apid: (NSString *) apid delegate: (id<MMAdDelegate>)delegate;
	

/**
 * Use this method to start conversion tracker.
 */
- (void) startConversionTrackerWithGoalId: (NSString *) goalid;
	
/**
 * Use this method to refresh the ad.
 */
- (void) refreshAd;	
	
/**
 * Use this method to enable ad refreshing.
 */
- (void)enableAdRefresh;

/**
 * Use this method to disable ad refreshing.
 */
- (void)disableAdRefresh;
	
	
+ (NSString *) version;

@end



@protocol MMAdDelegate<NSObject>
@optional
	
- (NSDictionary *) requestData;

// Set the timer duration for the rotation of ads in seconds. Default: 60
- (NSInteger) adRefreshDuration;
	
/**
 * Use this method to disable the accelerometer. Default: YES
 */	
- (BOOL) accelerometerEnabled;
	
// Return true to enable test mode.
- (BOOL) testMode;
	
/**
 * If the following methods are implemented, the delegate will be notified when
 * an ad request succeeds or fails. An ad request is considered to have failed
 * in any situation where no ad is recived.
 */



- (void)adDidRefresh:(MMAdView *)adView;


- (void)adRequestSucceeded:(MMAdView *) adView;
- (void)adRequestFailed:(MMAdView *) adView;
- (void)adDidRefresh:(MMAdView *)adView;
- (void)adWasTapped:(MMAdView *) adView;

//Asks the delegate to allow safari to be openned
- (void)applicationWillTerminateFromAd;


- (void)adModalWillAppear;
- (void)adModalDidAppear;
- (void)adModalWasDismissed;


@end