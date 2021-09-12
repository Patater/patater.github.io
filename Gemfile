source 'https://rubygems.org'
gem "github-pages", "~> 219", group: :jekyll_plugins

require 'rbconfig'
if RbConfig::CONFIG['target_os'] =~ /(?i-mx:bsd|dragonfly)/
  gem 'rb-kqueue', '>= 0.2'
end
