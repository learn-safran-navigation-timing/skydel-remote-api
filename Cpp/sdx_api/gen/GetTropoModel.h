#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get tropospheric model
    ///
    /// 
    ///

    class GetTropoModel;
    typedef std::shared_ptr<GetTropoModel> GetTropoModelPtr;
    
    
    class GetTropoModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetTropoModel();

      static GetTropoModelPtr create();
      static GetTropoModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

