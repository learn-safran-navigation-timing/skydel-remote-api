#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get OSNMA tag size.
    ///
    /// 
    ///

    class GetOsnmaTagSize;
    typedef std::shared_ptr<GetOsnmaTagSize> GetOsnmaTagSizePtr;
    
    
    class GetOsnmaTagSize : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetOsnmaTagSize();

      static GetOsnmaTagSizePtr create();
      static GetOsnmaTagSizePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

