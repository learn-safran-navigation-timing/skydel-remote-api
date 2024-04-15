#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Sets the mode for how the maximum number of entries in the Status Log is handled. The "Unlimited" mode allows the Status Log to have an infinite amount of entries. The "Custom" mode allows to set a maximum entries count for the Status Log. In that mode, when the maximum count is reached, Skydel will start overwritting the older entries in the Status Log.
    ///
    /// Name Type   Description
    /// ---- ------ ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Mode string Status Log maximum count mode, accepts "Unlimited" and "Custom". If "Custom" mode is set, use the command SetStatusLogMaxEntriesCount to set the maximum number of entries in the Status Log.
    ///

    class SetStatusLogMaxEntriesCountMode;
    typedef std::shared_ptr<SetStatusLogMaxEntriesCountMode> SetStatusLogMaxEntriesCountModePtr;
    
    
    class SetStatusLogMaxEntriesCountMode : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetStatusLogMaxEntriesCountMode();

      SetStatusLogMaxEntriesCountMode(const std::string& mode);

      static SetStatusLogMaxEntriesCountModePtr create(const std::string& mode);
      static SetStatusLogMaxEntriesCountModePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** mode ****
      std::string mode() const;
      void setMode(const std::string& mode);
    };
    
  }
}

