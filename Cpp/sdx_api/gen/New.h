#pragma once

#include <memory>
#include "command_base.h"

#include <optional>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Create a new configuration.
    ///
    /// Name                 Type          Description
    /// -------------------- ------------- ----------------------------------------------
    /// DiscardCurrentConfig bool          Discard current config even if it is not saved
    /// LoadDefaultConfig    optional bool Apply the default configuration
    ///

    class New;
    typedef std::shared_ptr<New> NewPtr;
    
    
    class New : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      New();

      New(bool discardCurrentConfig, const std::optional<bool>& loadDefaultConfig = {});

      static NewPtr create(bool discardCurrentConfig, const std::optional<bool>& loadDefaultConfig = {});
      static NewPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** discardCurrentConfig ****
      bool discardCurrentConfig() const;
      void setDiscardCurrentConfig(bool discardCurrentConfig);


      // **** loadDefaultConfig ****
      std::optional<bool> loadDefaultConfig() const;
      void setLoadDefaultConfig(const std::optional<bool>& loadDefaultConfig);
    };
    
  }
}

