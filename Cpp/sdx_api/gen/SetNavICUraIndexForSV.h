#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the URA index of a NavIC satellite
    ///
    /// Name Type Description
    /// ---- ---- -------------------
    /// SvId int  The satellite SV ID
    /// Urai int  URA index.
    ///

    class SetNavICUraIndexForSV;
    typedef std::shared_ptr<SetNavICUraIndexForSV> SetNavICUraIndexForSVPtr;
    
    
    class SetNavICUraIndexForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetNavICUraIndexForSV();

      SetNavICUraIndexForSV(int svId, int urai);
  
      static SetNavICUraIndexForSVPtr create(int svId, int urai);
      static SetNavICUraIndexForSVPtr dynamicCast(CommandBasePtr ptr);
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

