<?php
/**
 * @file
 * Defines routines for searching various custom targets.
 */

/**
 * Route searches to appropriate target handler.
 */
function ucla_search_route_search($search_info) {
  // Docs say drupal_goto is for "local" URLs but works fine with absolute off-site URLs too
  // ... is there a better choice?

  $search_terms = $search_info['search_terms'];

  switch ($search_info['search_target']) {
    case "site":
      $target_url = 'search/node/' . trim($search_terms);
      drupal_goto($path = $target_url);
      break;
    case "melvyl":
      $target_url = 'http://ucla.worldcat.org/search?qt=wc_org_ucla&q=';
      // Don't replace space with plus - URL-encode as-is
      $target_url .= drupal_encode_path($search_terms);
      drupal_goto($path = $target_url);
      break;
    case "catalog":
      $target_url = 'http://catalog.library.ucla.edu/cgi-bin/Pwebrecon.cgi?DB=local&Search_Arg=';
      $extra_params = '&Search_Code=GKEY^&SL=None&CNT=50&HIST=1';
      // Need to replace space with plus for library catalog, but do NOT url encode the terms
      $target_url .= str_replace(' ', '+', $search_terms);
      // Extra params must be after the search terms in the URL
      $target_url .= $extra_params;
      drupal_goto($path = $target_url);
      break;
    case "guides":
      $target_url = 'http://guides.library.ucla.edu/search.php?iid=261&c=0&search=';
      // Need to replace space with plus for subject guides, but do NOT url encode the terms
      $target_url .= str_replace(' ', '+', $search_terms);
      drupal_goto($path = $target_url);
      break;
    default:
      drupal_set_message("WHAT???");
  }
}

