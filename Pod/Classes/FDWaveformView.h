//
//  FDWaveformView
//
//  Created by William Entriken on 10/6/13.
//  Copyright (c) 2013 William Entriken. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>
#import <AVFoundation/AVFoundation.h>


@protocol FDWaveformViewDelegate;

@interface FDWaveformView : UIView
@property (nonatomic, weak) id<FDWaveformViewDelegate> delegate;
@property (nonatomic, strong) NSURL *audioURL;
@property (nonatomic, assign, readonly) unsigned long int totalSamples;
@property (nonatomic, assign) unsigned long int progressSamples;
@property (nonatomic, assign) unsigned long int zoomStartSamples;
@property (nonatomic, assign) unsigned long int zoomEndSamples;
@property (nonatomic) BOOL doesAllowScrubbing;
@property (nonatomic) BOOL doesAllowStretch;
@property (nonatomic) BOOL doesAllowScroll;
@property (nonatomic, copy) UIColor *wavesColor;
@property (nonatomic, copy) UIColor *progressColor;

@property (nonatomic, readonly) unsigned long int selectionStartSamples;
@property (nonatomic, readonly) unsigned long int selectionEndSamples;

@property (nonatomic, assign) CMTime assetDuration;

@property (nonatomic, assign) NSTimeInterval maxInterval;

@property (nonatomic, strong) AVAsset *asset;
@property (nonatomic, strong) AVAssetTrack *assetTrack;
@end

@protocol FDWaveformViewDelegate <NSObject>
@optional
- (void)waveformViewWillRender:(FDWaveformView *)waveformView;
- (void)waveformViewDidRender:(FDWaveformView *)waveformView;
- (void)waveformViewWillLoad:(FDWaveformView *)waveformView;
- (void)waveformViewDidLoad:(FDWaveformView *)waveformView;
- (void)waveformDidBeginPanning:(FDWaveformView *)waveformView;
- (void)waveformDidEndPanning:(FDWaveformView *)waveformView;
- (void)waveformDidSelectIntervalFrom:(unsigned long int)startSample toFinish:(unsigned long int)finishSample usingTimeScale:(CMTimeScale)timeScale;
@end