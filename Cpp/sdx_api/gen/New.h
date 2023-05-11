#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"

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


      New();

      New(bool discardCurrentConfig, const Sdx::optional<bool>& loadDefaultConfig = {});

      static NewPtr create(bool discardCurrentConfig, const Sdx::optional<bool>& loadDefaultConfig = {});
      static NewPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** discardCurrentConfig ****
      bool discardCurrentConfig() const;
      void setDiscardCurrentConfig(bool discardCurrentConfig);


      // **** loadDefaultConfig ****
      Sdx::optional<bool> loadDefaultConfig() const;
      void setLoadDefaultConfig(const Sdx::optional<bool>& loadDefaultConfig);
    };
    
  }
}

