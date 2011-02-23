namespace :device do
  namespace :iphone do
    namespace :production do
      desc "Builds, signs iphone for production and creates an app.ipa file"
      task :ipa do
      	$app_config["iphone"]["sdk"] = "iphoneos4.2"
		Rake::Task["device:iphone:production"].invoke
		`rm #{$app_path}/app.ipa` if File.exists?("#{$app_path}/app.ipa")
		`rm -rf /tmp/Payload` if File.exists?("/tmp/Payload")
		`mkdir /tmp/Payload`
		`cp -r #{$app_config["sdk"]}/platform/iphone/build/Distribution-iphoneos/rhorunner.app /tmp/Payload`
		Dir.chdir("/tmp") do
			`zip -r #{$app_path}/app.ipa Payload -x "*/.svn/"`
		end
		puts "app.ipa created successfully!"
      end
    end
  end
end
