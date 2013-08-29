<?php
/**
 * @file
 * Defines routines for logging search information.
 */

/**
 * Logs search info to database.
 */
function ucla_search_log_search($search_info) {
  db_insert('ucla_search_log')->fields($search_info)->execute();
}

