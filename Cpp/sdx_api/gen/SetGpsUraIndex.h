#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetGpsUraIndex is deprecated since 21.3. You may use SetGpsUraIndexForSV.
    /// 
    /// Set the ura index of a GPS satellite
    ///
    /// Name Type Description
    /// ---- ---- -----------------
    /// Prn  int  The satellite PRN
    /// Urai int  URA index.
    ///

    class SetGpsUraIndex;
    typedef std::shared_ptr<SetGpsUraIndex> SetGpsUraIndexPtr;
    
    
    class SetGpsUraIndex : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsUraIndex();

      SetGpsUraIndex(int prn, int urai);
  
      static SetGpsUraIndexPtr create(int prn, int urai);
      static SetGpsUraIndexPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** urai ****
      int urai() const;
      void setUrai(int urai);
    };
  }
}

