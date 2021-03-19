#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GPS nav data health
    ///
    /// Name Type Description
    /// ---- ---- -----------------------
    /// SvId int  Satellite's SV ID 1..32
    ///

    class GetGpsDataHealthForSV;
    typedef std::shared_ptr<GetGpsDataHealthForSV> GetGpsDataHealthForSVPtr;
    
    
    class GetGpsDataHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsDataHealthForSV();

      GetGpsDataHealthForSV(int svId);
  
      static GetGpsDataHealthForSVPtr create(int svId);
      static GetGpsDataHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

