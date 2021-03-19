#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get BeiDou satellite health info
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..35
    ///

    class GetBeiDouHealthInfoForSV;
    typedef std::shared_ptr<GetBeiDouHealthInfoForSV> GetBeiDouHealthInfoForSVPtr;
    
    
    class GetBeiDouHealthInfoForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouHealthInfoForSV();

      GetBeiDouHealthInfoForSV(int svId);
  
      static GetBeiDouHealthInfoForSVPtr create(int svId);
      static GetBeiDouHealthInfoForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

