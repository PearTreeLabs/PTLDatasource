//
//  PTLDatasource+TableView.h
//  PTLDatasource Demo
//
//  Created by Brian Partridge on 7/11/13.
//  Copyright (c) 2013 Pear Tree Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PTLDatasource.h"

typedef void(^PTLTableViewCellConfigBlock)(UITableView *tableView, UITableViewCell *cell, id item, NSIndexPath *indexPath);

#pragma mark - Protocol

@protocol PTLTableViewDatasource <PTLDatasource>

- (NSString *)tableViewCellIdentifierForIndexPath:(NSIndexPath *)indexPath;
- (PTLTableViewCellConfigBlock)tableViewCellConfigBlockForIndexPath:(NSIndexPath *)indexPath;

@optional
- (NSString *)tableViewSectionHeaderTitleForSection:(NSInteger)sectionIndex;
- (NSString *)tableViewSectionFooterTitleForSection:(NSInteger)sectionIndex;

@end

#pragma mark - Implementation

@interface PTLDatasource (TableView) <PTLTableViewDatasource>

@property (nonatomic, copy) NSString *tableViewSectionHeaderTitle;
@property (nonatomic, copy) NSString *tableViewSectionFooterTitle;
@property (nonatomic, copy) NSString *tableViewCellIdentifier;
@property (nonatomic, copy) PTLTableViewCellConfigBlock tableViewCellConfigBlock;

- (void)setTableViewSectionHeaderTitle:(NSString *)title forSection:(NSInteger)sectionIndex;
- (void)setTableViewSectionFooterTitle:(NSString *)title forSection:(NSInteger)sectionIndex;
- (void)setTableViewCellIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath *)indexPath;
- (void)setTableViewCellConfigBlock:(PTLTableViewCellConfigBlock)block forIndexPath:(NSIndexPath *)indexPath;

@end
