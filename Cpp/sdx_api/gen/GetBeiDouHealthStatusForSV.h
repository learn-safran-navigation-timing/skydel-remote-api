#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get BeiDou satellite health status
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..35
    ///

    class GetBeiDouHealthStatusForSV;
    typedef std::shared_ptr<GetBeiDouHealthStatusForSV> GetBeiDouHealthStatusForSVPtr;
    
    
    class GetBeiDouHealthStatusForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouHealthStatusForSV();

      GetBeiDouHealthStatusForSV(int svId);
  
      static GetBeiDouHealthStatusForSVPtr create(int svId);
      static GetBeiDouHealthStatusForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

