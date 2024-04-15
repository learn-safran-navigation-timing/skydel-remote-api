#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get ionospheric model
    ///
    /// 
    ///

    class GetIonoModel;
    typedef std::shared_ptr<GetIonoModel> GetIonoModelPtr;
    
    
    class GetIonoModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIonoModel();

      static GetIonoModelPtr create();
      static GetIonoModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

