#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// When SetStatusLogMaxEntriesCountMode is set to "Custom", this commands sets the maximum number of entries in the Status Log. Default value is 1000 entries.
    ///
    /// Name     Type Description
    /// -------- ---- --------------------------
    /// MaxCount int  Maximum number of entries.
    ///

    class SetStatusLogMaxEntriesCount;
    typedef std::shared_ptr<SetStatusLogMaxEntriesCount> SetStatusLogMaxEntriesCountPtr;
    
    
    class SetStatusLogMaxEntriesCount : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetStatusLogMaxEntriesCount();

      SetStatusLogMaxEntriesCount(int maxCount);

      static SetStatusLogMaxEntriesCountPtr create(int maxCount);
      static SetStatusLogMaxEntriesCountPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** maxCount ****
      int maxCount() const;
      void setMaxCount(int maxCount);
    };
    
  }
}

