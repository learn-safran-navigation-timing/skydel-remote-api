#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the ura index of a GPS satellite
    ///
    /// Name Type Description
    /// ---- ---- -------------------
    /// SvId int  The satellite SV ID
    /// Urai int  URA index.
    ///

    class SetGpsUraIndexForSV;
    typedef std::shared_ptr<SetGpsUraIndexForSV> SetGpsUraIndexForSVPtr;
    
    
    class SetGpsUraIndexForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsUraIndexForSV();

      SetGpsUraIndexForSV(int svId, int urai);
  
      static SetGpsUraIndexForSVPtr create(int svId, int urai);
      static SetGpsUraIndexForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** urai ****
      int urai() const;
      void setUrai(int urai);
    };
  }
}

