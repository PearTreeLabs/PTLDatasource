//
//  PTLTableViewDatasource.h
//  PTLDatasource Demo
//
//  Created by Brian Partridge on 7/11/13.
//  Copyright (c) 2013 Pear Tree Labs. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PTLDatasource.h"

typedef void(^PTLTableViewCellConfigBlock)(UITableView *tableView, UITableViewCell *cell, id item, NSIndexPath *indexPath);
typedef BOOL(^PTLTableViewCanEditRowBlock)(UITableView *tableView, id item, NSIndexPath *indexPath);
typedef void(^PTLTableViewCommitEditingStyleBlock)(UITableView *tableView, UITableViewCellEditingStyle editingStyle, id item, NSIndexPath *indexPath);

@protocol PTLTableViewDatasource <PTLDatasource, UITableViewDataSource>

- (NSString *)tableViewCellIdentifierForIndexPath:(NSIndexPath *)indexPath;
- (PTLTableViewCellConfigBlock)tableViewCellConfigBlockForIndexPath:(NSIndexPath *)indexPath;
- (PTLTableViewCanEditRowBlock)tableViewCanEditRowBlockForIndexPath:(NSIndexPath *)indexPath;
- (PTLTableViewCommitEditingStyleBlock)tableViewCommitEditingStyleBlockForIndexPath:(NSIndexPath *)indexPath;

@optional
- (NSString *)tableViewHeaderTitleForSection:(NSInteger)sectionIndex;
- (NSString *)tableViewFooterTitleForSection:(NSInteger)sectionIndex;

@end
