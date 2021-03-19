#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetBeiDouUraIndex is deprecated since 21.3. You may use SetBeiDouUraIndexForSV.
    /// 
    /// Set the ura index of a BeiDou satellite
    ///
    /// Name Type Description
    /// ---- ---- -----------------
    /// Prn  int  The satellite PRN
    /// Urai int  URA index.
    ///

    class SetBeiDouUraIndex;
    typedef std::shared_ptr<SetBeiDouUraIndex> SetBeiDouUraIndexPtr;
    
    
    class SetBeiDouUraIndex : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouUraIndex();

      SetBeiDouUraIndex(int prn, int urai);
  
      static SetBeiDouUraIndexPtr create(int prn, int urai);
      static SetBeiDouUraIndexPtr dynamicCast(CommandBasePtr ptr);
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

