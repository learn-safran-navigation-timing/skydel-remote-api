#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the WF antenna offset infos.
    ///
    /// 
    ///

    class GetWFAntennaOffset;
    typedef std::shared_ptr<GetWFAntennaOffset> GetWFAntennaOffsetPtr;
    
    
    class GetWFAntennaOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetWFAntennaOffset();

      static GetWFAntennaOffsetPtr create();
      static GetWFAntennaOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

