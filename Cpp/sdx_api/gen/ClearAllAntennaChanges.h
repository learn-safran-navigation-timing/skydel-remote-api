#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Clear all antenna changes.
    ///
    /// 
    ///

    class ClearAllAntennaChanges;
    typedef std::shared_ptr<ClearAllAntennaChanges> ClearAllAntennaChangesPtr;
    
    
    class ClearAllAntennaChanges : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllAntennaChanges();

      static ClearAllAntennaChangesPtr create();
      static ClearAllAntennaChangesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

