//
//  LOXWebViewController.h
//  LauncherOSX
//
//  Created by Boris Schneiderman.
//  Copyright (c) 2012-2013 The Readium Foundation.
//
//  The Readium SDK is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import <WebKit/WebResourceLoadDelegate.h>
#import "LOXSpineViewController.h"

@class LOXePubSdkApi;
@class LOXPageNumberTextController;
@class LOXBookmarksController;
@class LOXAppDelegate;
@class LOXPackage;
@class LOXCurrentPagesInfo;


@interface LOXWebViewController : NSObject<LOXSpineViewControllerDelegate> {

@private
    IBOutlet WebView *_webView;
}

- (void) clear;

- (void)onOpenPage:(NSString *)currentPaginationInfo;

@property (assign) IBOutlet NSButton *prevPageButton;
@property (assign) IBOutlet NSButton *nextPageButton;

@property (assign) IBOutlet LOXAppDelegate *appDelegate;

@property (nonatomic, retain) LOXCurrentPagesInfo *currentPagesInfo;

- (IBAction)onPrevPageClick:(id)sender;
- (IBAction)onNextPageClick:(id)sender;

- (void)openSpineItem:(id)idref elementCfi:(NSString *)cfi;

- (void)openSpineItem:(NSString *)idref pageIndex:(int)pageIx;

- (void)openPage:(int)pageIndex;

- (void)openContentUrl:(NSString *)contentRef fromSourceFileUrl:(NSString *)sourceRef;

- (NSString *)getCurrentPageCfi;

- (void)openPackage:(LOXPackage *)package;

@end
