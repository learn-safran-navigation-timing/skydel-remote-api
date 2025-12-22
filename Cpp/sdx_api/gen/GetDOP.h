#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the current Dilution of Precision (DOP) values as separate measurements.
    ///
    /// 
    ///

    class GetDOP;
    typedef std::shared_ptr<GetDOP> GetDOPPtr;
    
    
    class GetDOP : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetDOP();

      static GetDOPPtr create();
      static GetDOPPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

