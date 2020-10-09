//
//  ShareContentView.h
//  ZoomSDKSample
//
//  Created by TOTTI on 2018/7/26.
//  Copyright © 2018 zoom.us. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ShareContentView : NSView
{
    unsigned int _userid;
    NSView*      _shareView;
}
@property(nonatomic, retain) NSView* shareView;
@property(nonatomic, assign) unsigned int userid;
@end
