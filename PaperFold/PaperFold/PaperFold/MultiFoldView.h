//
//  MultiFoldView.h
//  PaperFold
//
//  Created by Hon Cheng Muh on 6/2/12.
//  Copyright (c) 2012 honcheng@gmail.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FoldView.h"

@interface MultiFoldView : UIView
// number of folds
@property (assign, nonatomic) int numberOfFolds;
// fraction of the view on the right to its immediate left
// determines when the next fold on the right should open
@property (assign, nonatomic) float pullFactor;
// indicate whether the fold is open or closed
@property (assign, nonatomic) FoldState state;

@property (assign, nonatomic) UIView *contentView;

// init with the number of folds and pull factor
- (id)initWithFrame:(CGRect)frame folds:(int)folds pullFactor:(float)pullFactor;
// set the content of the view
- (void)setContent:(UIView *)contentView;
// get screenshot of content to overlay in folds
- (void)drawScreenshotOnFolds;

// set fold states based on offset value
- (void)calculateFoldStateFromOffset:(float)offset;

// unfold the based on parent offset
- (void)unfoldWithParentOffset:(float)offset;

// unfold using a fraction 0 to 1
// 0 when it's completely folded
// 1 when it's completely unfolded
// fraction is calculated based on parent offset 
- (void)unfoldViewToFraction:(CGFloat)fraction;

// unfold foldView using fraction
- (void)unfoldView:(FoldView*)foldView toFraction:(CGFloat)fraction;

// show/hide all folds 
- (void)showFolds:(BOOL)show;

#pragma mark states
// states of folds
- (void)foldDidOpened;
- (void)foldDidClosed;
- (void)foldWillOpen;
- (void)foldWillClose;

@end
